
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_6001ad79(int param_1)

{
  undefined4 uVar1;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    uVar1 = FUN_6001adc1();
    *(undefined4 *)(param_1 + local_8 * 4) = uVar1;
  }
  return;
}

