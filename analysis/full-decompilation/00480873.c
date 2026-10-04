
void FUN_00480873(undefined2 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  undefined4 uVar4;
  undefined2 extraout_var_00;
  uint uVar3;
  
  FUN_0046fa24(0x28);
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),CONCAT22(extraout_var,param_1[1]),
               CONCAT22(extraout_var,*param_1),param_3,param_4);
  uVar2 = FUN_0046f847(s____dir_from_006c5848,0xffffffff);
  bVar1 = *(byte *)(param_1 + 2) & 1;
  uVar3 = CONCAT31((int3)((uint)uVar2 >> 8),*(byte *)(param_1 + 2)) & 0xffffff01;
  if (bVar1 == 0) {
    uVar2 = 0xb;
  }
  else {
    uVar2 = CONCAT22(extraout_var_00,param_1[3]);
  }
  if ((bVar1 & (byte)uVar3) == 0) {
    uVar4 = 3;
  }
  else {
    uVar4 = CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)((int)param_1 + 5));
  }
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),uVar4,uVar2,param_3,param_4);
  FUN_0046f847(s_to_stack_obj_006c5824,0xffffffff);
  FUN_0046fa24(0x29);
  return;
}

