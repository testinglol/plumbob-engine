
void __thiscall FUN_00594331(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  iVar2 = FUN_005942c4(param_2);
  if (iVar2 < 0) {
    uVar3 = FUN_005943a7(param_3,1);
    local_c = FUN_005943a7(param_2,1);
    local_8 = uVar3;
    FUN_0059adbe(&local_c);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      FUN_0041d9a9(iVar1);
    }
    iVar1 = *(int *)(param_1 + 4);
    uVar3 = FUN_005943a7(param_3,1);
    *(undefined4 *)(iVar2 * 8 + 4 + iVar1) = uVar3;
  }
  return;
}

