
void __fastcall FUN_005dc05f(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_8;
  
  local_10 = param_1[0x20];
  iVar3 = param_1[0x1f];
  iVar2 = param_1[0x21];
  local_8 = param_1[0x22];
  for (piVar1 = (int *)(**(code **)(*param_1 + 0x18))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*piVar1 + 0x18))()) {
    local_10 = local_10 + piVar1[0x20];
    local_8 = local_8 + piVar1[0x20];
    iVar3 = iVar3 + piVar1[0x1f];
    iVar2 = iVar2 + piVar1[0x1f];
  }
  param_1[3] = iVar3;
  param_1[4] = local_10;
  param_1[5] = iVar2;
  param_1[6] = local_8;
  if ((char)param_1[0xf] == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
  }
  piVar1 = *(int **)param_1[0xe];
  if (piVar1 != (int *)param_1[0xe]) {
    do {
      (**(code **)(*(int *)piVar1[2] + 0x88))();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)param_1[0xe]);
  }
  *(undefined1 *)(param_1 + 0xf) = 0;
  return;
}

