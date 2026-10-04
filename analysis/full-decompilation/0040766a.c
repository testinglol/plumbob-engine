
undefined2 FUN_0040766a(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  short sVar3;
  undefined2 uVar4;
  
  uVar4 = 0;
  piVar2 = DAT_006de808;
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[1];
    sVar3 = (**(code **)(iVar1 + 4))(param_1,param_2);
    if (sVar3 != 0) {
      uVar4 = 1;
    }
  }
  return uVar4;
}

