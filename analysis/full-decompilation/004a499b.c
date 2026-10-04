
undefined4 __thiscall FUN_004a499b(undefined1 *param_1,undefined4 param_2,char param_3,char param_4)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  float10 fVar7;
  char cStack0000000b;
  char cStack0000000f;
  undefined4 local_1c;
  undefined1 *local_c;
  undefined1 *local_8;
  
  cVar2 = param_3 + *(char *)(DAT_006e54d8 + 0x70);
  cVar6 = param_4 + *(char *)(DAT_006e54d8 + 0x78);
  _param_4 = (float)(int)cVar6;
  _param_3 = &local_1c;
  local_1c._0_2_ = CONCAT11(cVar6,cVar2);
  local_1c._3_1_ = (char)cVar6 >> 7;
  local_1c._0_3_ = CONCAT12(1,(undefined2)local_1c);
  local_c = param_1;
  local_8 = param_1;
  puVar3 = (undefined4 *)FUN_004796d9(&param_3);
  uVar1 = *puVar3;
  cStack0000000b = cVar2 + -1;
  _param_3 = SUB43(&local_1c,0);
  local_1c = (undefined1 *)CONCAT13(extraout_var,0x10000);
  local_1c._0_2_ = CONCAT11(param_4,cStack0000000b);
  puVar3 = (undefined4 *)FUN_004796d9(&local_8);
  local_8 = (undefined1 *)*puVar3;
  local_c = (undefined1 *)&local_1c;
  cVar6 = param_4 + -1;
  local_1c = (undefined1 *)CONCAT13(extraout_var_00,0x10000);
  local_1c._0_2_ = CONCAT11(cVar6,cStack0000000b);
  cStack0000000f = cVar6;
  _param_3 = (undefined4 *)FUN_004796d9(&param_3);
  _param_3 = (undefined4 *)*_param_3;
  local_c = (undefined1 *)&local_1c;
  local_1c._0_2_ = CONCAT11(cStack0000000f,cVar2);
  local_1c._0_3_ = CONCAT12(1,(undefined2)local_1c);
  local_1c = (undefined1 *)CONCAT13(extraout_var_01,(undefined3)local_1c);
  puVar3 = (undefined4 *)FUN_004796d9(&local_c);
  local_1c = (undefined1 *)*puVar3;
  fVar7 = (float10)FUN_004c4a42();
  local_1c = (undefined1 *)_param_3;
  _param_4 = (float)fVar7;
  fVar7 = (float10)FUN_004c4a98();
  local_1c = (undefined1 *)_param_3;
  _param_4 = (float)(fVar7 + (float10)_param_4);
  fVar7 = (float10)FUN_004c4a42();
  local_1c = local_8;
  _param_4 = (float)(fVar7 + (float10)_param_4);
  fVar7 = (float10)FUN_004c4a98();
  _param_4 = (float)(fVar7 + (float10)_param_4);
  local_1c = (undefined1 *)uVar1;
  fVar7 = (float10)FUN_004c4a98();
  _param_4 = (float)(fVar7 + (float10)_param_4);
  local_1c = (undefined1 *)uVar1;
  FUN_004c4a42();
  iVar5 = *(int *)(param_1 + 0x3c);
  _param_4 = (float)(*(int *)(param_1 + 0x38) - iVar5);
  local_1c = (undefined1 *)0x4a4ad2;
  iVar4 = __ftol();
  local_1c = *(undefined1 **)(param_1 + 0x30);
  iVar4 = iVar4 + iVar5;
  if (local_1c != (undefined1 *)0x0) {
    iVar5 = FUN_0046f59a();
    iVar4 = iVar4 + iVar5;
  }
  iVar5 = *(int *)(param_1 + 0x38);
  if (iVar4 < iVar5) {
    iVar4 = iVar5;
  }
  if (*(int *)(param_1 + 0x3c) < iVar4) {
    iVar4 = *(int *)(param_1 + 0x3c);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),(char)iVar4);
}

