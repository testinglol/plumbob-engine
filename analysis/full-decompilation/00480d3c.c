
void FUN_00480d3c(int param_1)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  FUN_0046fa24(0x28);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0x82,
               CONCAT22(extraout_var,(short)*(char *)(param_1 + 2)) + 3);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  FUN_0046f847(&DAT_006c25a8,0xffffffff);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0x83,
               CONCAT22(extraout_var_00,(short)*(char *)(param_1 + 3)) + 3);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  if ((~*(byte *)(param_1 + 6) & 2) == 0) {
    FUN_0046f847(s___no_failure_trees_006c54d0,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

