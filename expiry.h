
#ifndef EXPIRY_H
#define EXPIRY_H

#include "inventory.h"

void purgeExpired(int today);
void logExpiredBatch(Medicine m);
void displayExpiryLog();

#endif
