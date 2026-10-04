
void __fastcall FUN_005d8b48(int param_1)

{
  undefined1 local_308 [256];
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  undefined1 local_8 [4];
  
  (*(code *)PTR_FUN_006d71dc)(*(undefined4 *)(param_1 + 4),local_8,local_108,local_208,local_308);
  FUN_005d4bbf(local_8);
  FUN_005d4bbf(local_108);
  FUN_005d4bbf(local_208);
  FUN_005d4bbf(local_308);
  *(undefined1 *)(param_1 + 0x44) = 1;
  return;
}

