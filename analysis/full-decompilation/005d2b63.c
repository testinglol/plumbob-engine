
uint FUN_005d2b63(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = param_1;
  uVar3 = 0;
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    param_1 = (int *)0x0;
    uVar3 = (*(code *)*puVar1)(puVar2,&DAT_006772d8,&param_1);
    if (-1 < (int)uVar3) {
      iVar4 = (**(code **)(*param_1 + 0x58))(param_1,param_2);
      (**(code **)(*param_1 + 8))(param_1);
      return (uint)(-1 < iVar4);
    }
  }
  return uVar3 & 0xffffff00;
}

