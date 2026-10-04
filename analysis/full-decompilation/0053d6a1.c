
char FUN_0053d6a1(byte param_1)

{
  char cVar1;
  
  cVar1 = (param_1 & 1) != 0;
  if ((param_1 & 2) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 4) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 8) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 0x10) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 0x20) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 0x40) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((param_1 & 0x80) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}

