
void FUN_00476afb(short param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_0042573e((int)param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_00401f73();
    uVar2 = FUN_004e988f(uVar2);
    uVar2 = FUN_00476603(uVar2);
    piVar3 = (int *)FUN_00476b41(uVar2);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x160))(param_2);
    }
  }
  return;
}

