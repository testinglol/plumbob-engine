
undefined4 __thiscall FUN_00406c47(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  FUN_004659fc(0);
  uVar3 = 0;
  FUN_004659fc(0xffffff9d);
  piVar5 = (int *)(param_1 + 0xc);
  while( true ) {
    if ((int *)*piVar5 == (int *)0x0) {
      return uVar3;
    }
    uVar3 = (**(code **)(*(int *)*piVar5 + 0x4c))(param_2);
    uVar1 = FUN_00401f6f();
    FUN_004659fc(uVar1);
    iVar2 = FUN_00401f6f();
    if (iVar2 == 0) break;
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 5;
    if (7 < iVar4) {
      return uVar3;
    }
  }
  return uVar3;
}

