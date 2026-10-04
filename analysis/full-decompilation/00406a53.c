
int __thiscall
FUN_00406a53(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_8;
  
  FUN_004659fc(0);
  FUN_004659fc(0xffffff9e);
  local_8 = 0;
  piVar3 = (int *)(param_1 + 0xc);
  while( true ) {
    if ((int *)*piVar3 == (int *)0x0) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)*piVar3 + 0x44))(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) break;
    uVar2 = FUN_00401f6f();
    FUN_004659fc(uVar2);
    local_8 = local_8 + 1;
    piVar3 = piVar3 + 5;
    if (7 < local_8) {
      return 0;
    }
  }
  FUN_004659fc(0);
  return iVar1;
}

