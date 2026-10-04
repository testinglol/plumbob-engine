
undefined4 __fastcall FUN_0057d947(int param_1)

{
  char *pcVar1;
  
  FUN_0057da7d();
  pcVar1 = (char *)(param_1 + 0x280);
  if (*pcVar1 != '\0') {
    *pcVar1 = '\0';
  }
  *(undefined1 *)(param_1 + 0x1d4) = 0;
  return CONCAT31((int3)((uint)pcVar1 >> 8),1);
}

