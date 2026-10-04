
void __thiscall FUN_005de04b(int *param_1,char param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(DAT_006fe8f4 + 500);
  if ((param_2 != '\0') && (cVar2 = (**(code **)(*param_1 + 0x8c))(1), cVar2 != '\0')) {
    FUN_004cb21d(param_1[3] + (((param_1[0x21] - piVar1[0x21]) - param_1[0x1f]) + piVar1[0x1f]) / 2,
                 param_1[4] + -3 + (piVar1[0x20] - piVar1[0x22]));
    (**(code **)(*piVar1 + 0x94))();
    (**(code **)(*piVar1 + 0x44))();
    uVar3 = FUN_005e749a(0);
    FUN_005dde6d(uVar3);
    return;
  }
  (**(code **)(*piVar1 + 0x98))();
  return;
}

