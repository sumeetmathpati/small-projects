from flask import Flask, jsonify, request, url_for, redirect, session, render_template, g
import sqlite3

app = Flask(__name__)
app.config['DEBUG'] = True
app.config['SECRET_KEY'] = 'secret'

def connect_db():
	sql = sqlite3.connect('./data.db')
	sql.row_factory = sqlite3.Row
	return sql

def get_db():

	if not hasattr(g, 'sqlite3'):
		g.sqlite_db = connect_db()
	return g.sqlite_db

@app.teardown_appcontext
def close_db(error):
	if hasattr(g, 'sqlite_db'):
		g.sqlite_db.close()

@app.route('/')
def index():
	return f'<h1>Hello world! </h1>'

@app.route('/hello')
def hello():
	name = session['name']
	return f'<h1>Hello {name} </h1>'

@app.route('/home', methods=['GET', 'POST'], defaults={'name': 'John Doe'})
@app.route('/home/<string:name>', methods=['GET', 'POST'])
def home(name):
	session['name'] = name

	db = get_db()
	cur = db.execute('SELECT id, name, location FROM users;')
	results = cur.fetchall()

	return render_template('home.html', name=name, lst=[1, 2, 3, 4], results=results)
	

@app.route('/json')
def json():
	return jsonify({'key': 'value', 'key1': [1, 2, 3]})


@app.route('/query')
def query():

	name = request.args.get('name')
	age = request.args.get('age')

	return f'<h1>Hi {name}. You are on the query page.</h1>' + (f'<h2> Your age is {age}.' if age else '.')


@app.route('/theform', methods=['GET', 'POST'])
def theform():
	if request.method == 'GET':
		return render_template('form.html')
	else:
		name = request.form['name']
		location = request.form['location']

		db = get_db()
		db.execute('INSERT INTO users (name, location) values (?, ?)', [name, location])
		db.commit()

		return redirect(url_for('home', name=name, location=location))


@app.route('/viewresults')
def viewresults():
	db = get_db()
	cur = db.execute('SELECT id, name, location FROM users;')
	results = cur.fetchall()
	return 'The id is {}. The name is {}. The location is {}.'.format(results[1]['id'], results[1]['name'], results[1]['location'])
