
void __fastcall FUN_004cf47f(int param_1)

{
  FUN_004934bf();
  if (DAT_006e5780 != '\0') {
    FUN_0040766a(0x91,0);
    DAT_006e5780 = '\0';
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 4;
  return;
}

