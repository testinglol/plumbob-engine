
int FUN_0063c5d0(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_0063d88b(0x19);
  iVar2 = 0;
  while (param_2 != 0) {
    if ((*param_1 == 0) ||
       ((iVar1 = param_2 + -1, (*(byte *)((int)&DAT_00705240 + *param_1 + 1) & 4) != 0 &&
        ((iVar1 = param_2 + -2, param_2 + -1 == 0 || (param_1 = param_1 + 1, *param_1 == 0))))))
    break;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = iVar1;
  }
  FUN_0063d8ec(0x19);
  return iVar2;
}

