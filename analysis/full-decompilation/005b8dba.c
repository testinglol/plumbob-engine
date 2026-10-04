
int FUN_005b8dba(char *param_1)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = 0;
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    pcVar1 = param_1 + 1;
    uVar3 = (uVar3 + (int)cVar2) * 0x401;
    param_1 = param_1 + 1;
    uVar3 = uVar3 ^ uVar3 >> 6;
    cVar2 = *pcVar1;
  }
  return (uVar3 * 9 >> 0xb ^ uVar3 * 9) * 0x8001;
}

