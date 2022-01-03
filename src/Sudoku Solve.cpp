// Sun 02 Jan 2022 09:40:15 AM EST
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

int map[ 9 ][ 9 ];

void draw_map ()
{
	for ( int i = 0; i < 9; i++ ) {

		for ( int j = 0; j < 9; j++ )
			cout << map[ i ][ j ] << " ";
		cout << "\n";

	}

}

char find_free ( int &x, int &y )
{
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
			if ( map[ i ][ j ] == 0 ) {

				x = i; 
				y = j;
				return FALSE;
			
			}
	return TRUE;
}

int is_valid ( int n, int x, int y )
{
	   	for ( int i = 0; i < 9; i++ )
			if ( map[ x ][ i ] == n || map[ i ][ y ] == n )
				return FALSE;

		int x_location = ( x / 3 ) * 3;
		int y_location = ( y / 3 ) * 3;

		for ( int i = x_location; i < x_location + 3; i++ )
			for ( int j = y_location; j < y_location + 3; j++ )
				if ( map[ i ][ j ] == n )
					return FALSE;

		return TRUE;
}

int solve ()
{
	int x, y;
	if ( find_free ( x , y ) )
		return TRUE;

	for ( int i = 1; i <= 9; i++ ) {
		if ( is_valid( i , x , y ) ) {
			map[ x ][ y ] = i;
			if ( solve() )
				return TRUE;
			map[ x ][ y ] = 0;
		}
	}

	return FALSE;
}
		
int main()
{
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 9; j++ )
			cin >> map[ i ][ j ];

	if ( solve() )
		draw_map();

	return EXIT_SUCCESS;
}
