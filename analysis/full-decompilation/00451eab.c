
undefined4 __thiscall FUN_00451eab(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  uint uVar4;
  undefined2 uStack_16;
  undefined2 local_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined4 local_c;
  float *local_8;
  
  uVar1 = *param_3;
  uVar2 = param_3[1];
  uStack_16 = (undefined2)((uint)uVar1 >> 0x10);
  local_14 = (undefined2)uVar2;
  uStack_12 = (undefined2)((uint)uVar2 >> 0x10);
  *(undefined4 ***)(param_1 + 0x128) = &param_3;
  param_3 = (undefined4 *)0x0;
  local_8 = (float *)0x0;
  *(float ***)(param_1 + 300) = &local_8;
  FUN_00453181(CONCAT22(local_14,uStack_16),uVar1,1);
  sVar3 = FUN_00453181(CONCAT22(uStack_10,uStack_12),uVar2,0);
  if (sVar3 == 0) {
    local_c = 4;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_c,&DAT_00698f30);
  }
  if (param_3 == (undefined4 *)0x0) {
    if (local_8 == (float *)0x0) {
      local_c = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&local_c,&DAT_00698f30);
    }
    uVar4 = FUN_0046f556();
    *local_8 = (float)(int)(uVar4 % (uint)(int)sVar3);
  }
  else {
    uVar4 = FUN_0046f556();
    *(short *)param_3 = (short)(uVar4 % (uint)(int)sVar3);
  }
  return 1;
}

