
void __thiscall FUN_00555aa3(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (*(char *)(param_1 + 0x12a) != '\0') {
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x14c);
    do {
      if (*(int *)(*piVar1 + 0x1d8) == *(int *)(param_1 + 0x124)) break;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 9);
    iVar2 = *(int *)(param_1 + 0x14c + iVar2 * 4);
    if (param_2 == 0x25) {
      *(int *)(iVar2 + 0x208) = *(int *)(iVar2 + 0x208) + -1;
    }
    if (param_2 == 0x27) {
      *(int *)(iVar2 + 0x208) = *(int *)(iVar2 + 0x208) + 1;
    }
    if (param_2 == 0x26) {
      *(int *)(iVar2 + 0x20c) = *(int *)(iVar2 + 0x20c) + -1;
    }
    if (param_2 == 0x28) {
      *(int *)(iVar2 + 0x20c) = *(int *)(iVar2 + 0x20c) + 1;
    }
    local_c = *(int *)(iVar2 + 0x208);
    local_8 = *(int *)(iVar2 + 0x20c);
    if (*(int *)(iVar2 + 0x1ec) < 0) {
      local_c = local_c + *(int *)(iVar2 + 0x1ec);
    }
    if (*(int *)(iVar2 + 0x1f0) < 0) {
      local_8 = local_8 + *(int *)(iVar2 + 0x1f0);
    }
    local_8 = *(int *)(param_1 + 0x148) + local_8;
    local_c = *(int *)(param_1 + 0x144) + local_c;
    FUN_0054ec7a(&local_c);
  }
  return;
}

