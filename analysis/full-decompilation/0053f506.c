
undefined1 * __thiscall
FUN_0053f506(uint param_1,undefined1 *param_2,undefined1 *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = param_1;
  if (((param_4 == 0) || (param_4 == 2)) || (param_4 == 4)) {
    local_c = (uint)CONCAT11((&DAT_006e481d)[param_4 * 3],(&DAT_006e481c)[param_4 * 3]);
    puVar1 = &local_c;
  }
  else if (param_4 == 6) {
    local_8._0_2_ = CONCAT11(DAT_006e481d,DAT_006e481c);
    local_8 = CONCAT22((short)(param_1 >> 0x10),(undefined2)local_8) & 0xff00ffff;
    puVar1 = &local_8;
  }
  else {
    if (param_4 != 7) {
      *param_2 = *param_3;
      param_2[1] = param_3[1];
      param_2[2] = param_3[2];
      return param_2;
    }
    param_4._0_2_ = CONCAT11(DAT_006e4823,DAT_006e4822);
    param_4 = (uint)(ushort)param_4;
    puVar1 = &param_4;
  }
  FUN_0044f2cf(param_2,puVar1);
  return param_2;
}

