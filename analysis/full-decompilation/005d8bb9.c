
void __fastcall FUN_005d8bb9(int param_1)

{
  undefined1 local_108 [260];
  
  (*(code *)PTR_FUN_006d71d0)
            (local_108,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x20),
             *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x38));
  FUN_005d4bbf(local_108);
  *(undefined1 *)(param_1 + 0x10) = 1;
  return;
}

