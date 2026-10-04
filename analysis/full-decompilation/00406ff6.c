
void __thiscall FUN_00406ff6(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  FUN_004659fc(0);
  FUN_004659fc(0xffffff9d);
  iVar4 = 0;
  piVar5 = (int *)(param_1 + 0xc);
  do {
    if ((int *)*piVar5 == (int *)0x0) {
      return;
    }
    cVar1 = (**(code **)(*(int *)*piVar5 + 0x20))();
    if (cVar1 != '\0') {
      (**(code **)(*(int *)*piVar5 + 0x7c))(param_2);
      uVar2 = FUN_00401f6f();
      FUN_004659fc(uVar2);
      iVar3 = FUN_00401f6f();
      if (iVar3 == 0) {
        return;
      }
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 5;
  } while (iVar4 < 8);
  return;
}

