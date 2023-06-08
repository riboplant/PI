#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bagTAD.h"





int main(void){
bagADT bag = newBag();
	assert( add(bag, "agustina") == 1 );
	assert( add(bag, "agustina") == 2 );
	assert( add(bag, "belen") == 1 );
	assert( add(bag, "carla") == 1 );
	assert( add(bag, "carla") == 2 );
	assert( add(bag, "carla") == 3 );
	assert( add(bag, "daniel") == 1 );
	assert( add(bag, "emilio") == 1 );

	assert( count(bag, "carla") == 3 );
	assert( count(bag, "agustina") == 2 );
	assert( count(bag, "amelia") == 0 );
	assert( count(bag, "emilio") == 1 );
	assert( count(bag, "daniel") == 1 );
	assert( count(bag, "belen") == 1 );
	assert( size(bag) == 5 );
	assert( compare(mostPopular(bag), "carla") == 0 );

    for(int i=2; i <= 10001; i++)
        assert( add(bag, "belen") == i );
    assert(count(bag, "carla") == 3);
    assert(count(bag, "belen") ==10001);
    assert( compare(mostPopular(bag), "belen") == 0 );

    freeBag( bag );
    puts("OK!");

    bag = newBag();
    puts("Al buscar el más popular de un bag vacío debe abortar");
    mostPopular(bag);
    puts("Si ud. ve esto, entonces no abortó como debería haber hecho");
    return 0;
}