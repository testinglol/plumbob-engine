
char FUN_00607af9(int *param_1)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\0';
  iVar1 = (**(code **)*param_1)(param_1,&DAT_00677228,&param_1);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,&DAT_006d9348,1,0,0,&stack0x00000008,4);
    cVar2 = '\x01' - (iVar1 != 0);
    (**(code **)(*param_1 + 8))(param_1);
  }
  return cVar2;
}

