
void __thiscall FUN_00431c90(int *param_1,short param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_c4 [2];
  short local_c2;
  undefined2 local_9a;
  undefined2 local_94;
  undefined2 local_8a;
  undefined2 local_72;
  undefined2 local_6a;
  undefined2 local_68;
  undefined2 local_66;
  undefined2 local_3e;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined2 local_c;
  
  local_30 = 0;
  local_2c = 0;
  FUN_004328f3(local_34);
  FUN_00432984();
  FUN_005a92b0(local_c4,(int)param_1 + 0x4a,0x90);
  FUN_005a9250((int)param_1 + 0x4a,0,0x90);
  *(undefined2 *)(param_1 + 0x21) = local_8a;
  *(short *)(param_1 + 0x13) = local_c2;
  while (local_c2 < 0) {
    *(short *)(param_1 + 0x13) = (short)param_1[0x13] + 8;
    local_c2 = (short)param_1[0x13];
  }
  *(ushort *)(param_1 + 0x13) = *(ushort *)(param_1 + 0x13) & 7;
  *(undefined2 *)(param_1 + 0x27) = local_72;
  *(undefined2 *)(param_1 + 0x29) = local_6a;
  *(undefined2 *)((int)param_1 + 0xa6) = local_68;
  *(undefined2 *)(param_1 + 0x2a) = local_66;
  *(undefined2 *)((int)param_1 + 0x7a) = local_94;
  *(undefined2 *)(param_1 + 0x1d) = local_9a;
  *(undefined2 *)(param_1 + 0x34) = local_3e;
  *(short *)(param_1 + 0x18) = (short)param_1[0x3c];
  *(undefined2 *)((int)param_1 + 0xbe) = *(undefined2 *)(param_1[0x46] + 0x62);
  FUN_005a9250(param_1[0xb],0,param_1[0xc] << 1);
  FUN_005a9250((int)param_1 + 0x3a,0,0x10);
  FUN_00457da4();
  uVar4 = *(undefined4 *)(param_1[0x47] + 0xc);
  uVar3 = FUN_004561a0(1);
  FUN_00474979(uVar4,uVar3);
  FUN_004327d9(local_34);
  local_18 = 0;
  local_14 = 0;
  FUN_00432664(local_1c);
  if (local_10 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined2 *)(local_10 + 0xf0);
  }
  *(undefined2 *)((int)param_1 + 0x4e) = uVar2;
  *(undefined2 *)(param_1 + 0x14) = local_c;
  FUN_00432396();
  FUN_00431e78((int)(short)param_1[0x3c],0xffffffff);
  if (*(short *)(param_1[0x46] + 0x14) == 0) {
    FUN_00422d79(0,0,0);
    if (param_2 != 0) {
      (**(code **)(*param_1 + 0x14))(0);
    }
    FUN_0044582f((int)(short)param_1[0x3c],2,*(short *)((int)param_1 + 0xc2) != 0);
    iVar1 = param_1[0x3c];
    uVar4 = FUN_004359a1();
    FUN_0044582f((int)(short)iVar1,8,uVar4);
  }
  return;
}

