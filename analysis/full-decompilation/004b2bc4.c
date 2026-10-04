
undefined1
FUN_004b2bc4(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  short sVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 local_34 [20];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004aa1b9(local_20,&local_c,local_1c,&local_8);
  if (param_3 == 0) {
    local_14 = 0x3f;
    local_10 = 0x2f;
    param_3 = 0x3da3d70a;
  }
  else {
    local_14 = 0x14a;
    local_10 = 0xdc;
    param_3 = 0x3ecccccd;
  }
  local_c = 0x7fffffff;
  local_8 = 0x7fffffff;
  sVar1 = *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18);
  *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = 0;
  FUN_004c482f();
  (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))(0);
  FUN_00466c7b();
  FUN_004e609e();
  local_18 = FUN_004e6141();
  uVar5 = 2;
  FUN_004e609e(2);
  FUN_004e6166(uVar5);
  uVar3 = FUN_005dfe3b(param_4,param_5,param_6);
  puVar4 = (undefined4 *)
           FUN_004b2d29(local_14,local_10,0,1,local_c,local_8,param_3,local_34,param_2,0,uVar3,0,1);
  *(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = sVar1;
  FUN_004c482f();
  (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))((int)sVar1);
  FUN_00466c7b();
  uVar5 = local_18;
  FUN_004e609e(local_18);
  FUN_004e6166(uVar5);
  if (puVar4 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004b818c(param_1,puVar4,0,0x5a,0,0);
    (**(code **)*puVar4)(1);
  }
  return uVar2;
}

