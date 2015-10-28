/*******************************************************************
 * SQL-GAC: SQL Client for the SI-GAC project.
 * 
 * It contains operations for making SQL operations.
 * 
 * Copyright (c) 2015    Fernando Fonseca <fetofs@gmail.com> 
 * Copyright (c) 2015    Rodrigo Roim <roim.rodrigo@gmail.com> 
 *  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *******************************************************************/

// Declare the execSqlOperation function.
int execSqlOperation(const char* sqlOperation);

// Declare the sendHttpSqlRequest function.
char* sendHttpSqlRequest(const char* sqlOperation);
