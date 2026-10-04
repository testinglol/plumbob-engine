
void __thiscall FUN_0055d487(int param_1,int param_2)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(char *)(param_1 + 0x121) != '\0') {
    local_8 = *(int *)(*(int *)(param_1 + 0x148) + 8);
    if (local_8 != *(int *)(param_1 + 0x148)) {
      do {
        if (*(int *)(*(int *)(local_8 + 0x14) + 0x1d8) == *(int *)(param_1 + 0x11c)) break;
        FUN_0041674f();
      } while (local_8 != *(int *)(param_1 + 0x148));
    }
    iVar1 = *(int *)(local_8 + 0x14);
    if (param_2 == 0x25) {
      *(int *)(iVar1 + 0x208) = *(int *)(iVar1 + 0x208) + -1;
    }
    if (param_2 == 0x27) {
      *(int *)(iVar1 + 0x208) = *(int *)(iVar1 + 0x208) + 1;
    }
    if (param_2 == 0x26) {
      *(int *)(iVar1 + 0x20c) = *(int *)(iVar1 + 0x20c) + -1;
    }
    if (param_2 == 0x28) {
      *(int *)(iVar1 + 0x20c) = *(int *)(iVar1 + 0x20c) + 1;
    }
    local_c = *(int *)(iVar1 + 0x20c);
    local_10 = *(int *)(iVar1 + 0x208);
    if (*(int *)(iVar1 + 0x200) < 0) {
      local_10 = local_10 + *(int *)(iVar1 + 0x200);
    }
    if (*(int *)(iVar1 + 0x204) < 0) {
      local_c = local_c + *(int *)(iVar1 + 0x204);
    }
    local_10 = *(int *)(param_1 + 0x140) + local_10;
    local_c = *(int *)(param_1 + 0x144) + local_c;
    FUN_0054ec7a(&local_10);
  }
  return;
}

