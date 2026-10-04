
void FUN_004730c5(undefined2 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 local_8;
  
  puVar2 = param_1;
  puVar1 = param_1 + 1;
  local_8._1_1_ = (undefined1)((ushort)*param_1 >> 8);
  local_8._0_1_ = (undefined1)*param_1;
  param_1._1_1_ = (undefined1)((ushort)*puVar1 >> 8);
  local_8 = CONCAT11((undefined1)local_8,local_8._1_1_);
  param_1._0_1_ = (undefined1)*puVar1;
  param_1._0_2_ = CONCAT11(param_1._0_1_,param_1._1_1_);
  *puVar2 = param_1._0_2_;
  puVar2[1] = local_8;
  return;
}

