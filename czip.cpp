#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#pragma pack (push,1)
struct EOCD {
	u_int32_t sygnatur;
	byte t1[6];
	u_int16_t l_rekordow;
	byte t2[4];
	u_int32_t offset;
	byte t3[2];
};
#pragma pack (pop)
static_assert(sizeof(EOCD) == 22);


int main(){
	string filenazwa;
	cin >> filenazwa;
	
	ifstream file(filenazwa,ios::binary);
	assert(!file.fail());

	file.seekg(-22, ios::end);
	assert(!file.fail());

	EOCD eocd;
	file.read((char*) &eocd, 22);
	assert(!file.fail());

	assert(eocd.sygnatur == 0x06054b50);

	file.seekg(eocd.offset, ios::beg);
}
