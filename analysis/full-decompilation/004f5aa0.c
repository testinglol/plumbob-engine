
void __thiscall FUN_004f5aa0(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(int *)(param_1 + 0x90) == 0) || (*(char *)(param_1 + 0xf5) != '\0')) {
    if (*DAT_006e486c == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*DAT_006e486c + 0x10);
    }
    if (iVar1 != 0) {
      for (puVar2 = *(undefined4 **)(iVar1 + 300); puVar2 != *(undefined4 **)(iVar1 + 0x130);
          puVar2 = puVar2 + 1) {
        FUN_004eb208(*puVar2);
      }
    }
    *(undefined1 *)(param_1 + 0xf9) = 1;
  }
  else if (param_2 != '\0') {
    FUN_004f649a(0xfffffffe);
  }
  return;
}

