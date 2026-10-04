
undefined4 FUN_0063d48f(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 < DAT_00704100) &&
     ((*(byte *)((&DAT_00704000)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_006459ff(param_1);
    uVar1 = FUN_0063d4f4(param_1,param_2,param_3);
    FUN_00645a5e(param_1);
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_0063d796();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_0063d79f();
  *puVar2 = 0;
  return 0xffffffff;
}

