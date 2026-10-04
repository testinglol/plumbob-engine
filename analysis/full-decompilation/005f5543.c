
void __thiscall FUN_005f5543(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  iVar1 = param_1[0x3e];
  if (iVar1 != -1) {
    FUN_005e46f0(0);
  }
  param_1[0x3e] = param_2;
  if ((param_2 < 0) || (param_1[0x36] - param_1[0x35] >> 2 <= param_2)) {
    param_1[0x3e] = -1;
  }
  iVar5 = param_1[0x3e];
  if (iVar5 == -1) goto LAB_005f5609;
  if (iVar5 < param_1[0x3b]) {
    FUN_005f57e2(iVar5);
    iVar5 = param_1[0x3e];
    iVar3 = *(int *)param_1[0x38];
LAB_005f55ed:
    (**(code **)(iVar3 + 0x1a8))(iVar5);
  }
  else if (param_1[0x3b] + param_1[0x3a] <= iVar5) {
    FUN_005f57e2((iVar5 - param_1[0x3a]) + 1);
    iVar3 = *(int *)param_1[0x38];
    iVar5 = (param_1[0x3e] - param_1[0x3a]) + 1;
    goto LAB_005f55ed;
  }
  FUN_005e46f0(1);
LAB_005f5609:
  if (iVar1 != param_1[0x3e]) {
    local_14 = 3;
    local_10 = 0x15;
    local_c = param_1[0x3e];
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
    if (puVar4 != (undefined4 *)0x0) {
      cVar2 = FUN_005da398(puVar4);
      if (cVar2 != '\0') {
        (**(code **)*puVar4)(&local_14);
      }
    }
  }
  (**(code **)(*param_1 + 0x168))();
  return;
}

