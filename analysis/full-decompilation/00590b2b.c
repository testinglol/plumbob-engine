
void __fastcall FUN_00590b2b(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x150) != '\0') {
    *(undefined1 *)(param_1 + 0x150) = 0;
    iVar2 = FUN_00599121(0x1f);
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(param_1 + 0x154);
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(param_1 + 0x158);
    uVar1 = *(undefined4 *)(param_1 + 0x160);
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(param_1 + 0x15c);
    *(undefined4 *)(iVar2 + 0x48) = uVar1;
    FUN_00596177(*(int *)(iVar2 + 0x24) + 0x4c,*(int *)(iVar2 + 0x24) + 0x58);
    FUN_005a1466(0x1f,0);
  }
  return;
}

