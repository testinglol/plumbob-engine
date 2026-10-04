
void __fastcall FUN_0041ffbf(int param_1)

{
  undefined4 *puVar1;
  
  while (puVar1 = *(undefined4 **)(param_1 + 8), puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 8) = *puVar1;
    FUN_00634ecc(puVar1);
  }
  return;
}

