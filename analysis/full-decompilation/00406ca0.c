
void __thiscall FUN_00406ca0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  FUN_004659fc(0);
  FUN_004659fc(0xffffff9d);
  piVar4 = (int *)(param_1 + 0xc);
  while( true ) {
    if ((int *)*piVar4 == (int *)0x0) {
      return;
    }
    (**(code **)(*(int *)*piVar4 + 0x50))(param_2,param_3);
    uVar1 = FUN_00401f6f();
    FUN_004659fc(uVar1);
    iVar2 = FUN_00401f6f();
    if (iVar2 == 0) break;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 5;
    if (7 < iVar3) {
      return;
    }
  }
  return;
}

