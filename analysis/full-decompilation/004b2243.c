
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2243(int param_1,int *param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  undefined **local_b8 [3];
  undefined1 local_ac [64];
  int local_6c;
  int local_68 [6];
  undefined4 local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28 [3];
  int local_1c;
  int local_18;
  int local_14;
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  FUN_004aa1b9(&local_48,&local_18,&local_40,&local_14);
  bVar5 = (char)DAT_006f0088 + 1;
  local_28[2] = (((*(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x28)) - local_48) + local_18 >>
                (bVar5 & 0x1f)) / 2;
  iVar6 = 1 << ((char)DAT_006f0088 - 1U & 0x1f);
  local_2c = (((*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c)) - local_40) + local_14 >>
             (bVar5 & 0x1f)) / 2;
  local_18 = local_18 / iVar6;
  local_14 = local_14 / iVar6;
  local_1c = (int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18);
  *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = 0;
  FUN_004c482f();
  (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))(0);
  FUN_00466c7b();
  FUN_004e609e();
  local_50 = FUN_004e6141();
  uVar7 = 2;
  FUN_004e609e(2);
  FUN_004e6166(uVar7);
  local_28[0] = 0;
  local_28[1] = 0;
  local_10 = (undefined4 *)0x0;
  local_8 = 0;
  do {
    piVar2 = (int *)FUN_004b2d29(local_28[2],local_2c,0,1,local_18,local_14,_DAT_00668220,local_68,2
                                 ,CONCAT31((int3)((uint)&local_10 >> 8),local_8 == 1),DAT_006f2a64,
                                 &local_10,0);
    *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = (undefined2)local_1c;
    FUN_004c482f();
    (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))(local_1c);
    FUN_00466c7b();
    uVar7 = local_50;
    FUN_004e609e(local_50);
    FUN_004e6166(uVar7);
    if (piVar2 == (int *)0x0) {
LAB_004b257f:
      if (local_10 == (undefined4 *)0x0) {
        return;
      }
      (**(code **)*local_10)(1);
      return;
    }
    cVar1 = (**(code **)(*piVar2 + 0x20))(0x40);
    if (cVar1 == '\0') {
      if (piVar2 != (int *)0x0) {
        (**(code **)*piVar2)(1);
      }
      goto LAB_004b257f;
    }
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    FUN_004c3766(piVar2,piVar2 + 5,CONCAT22((short)((uint)&local_3c >> 0x10),(short)piVar2[9]),
                 &local_3c);
    local_6c = (local_2c - local_30) - local_38;
    local_44 = (local_28[2] - local_34) - local_3c;
    if (local_8 == 0) {
      local_68[1] = local_68[1] - local_38;
      local_68[0] = local_68[0] - local_3c;
      local_68[5] = local_38;
      local_4c = local_3c;
      local_68[4] = 0;
      local_68[3] = 0;
    }
    else {
      local_68[4] = local_38 - local_68[5];
      local_68[3] = local_3c - local_4c;
    }
    local_c = (**(code **)(*piVar2 + 0xcc))();
    uVar3 = (**(code **)(*piVar2 + 0xd0))();
    local_c = FUN_004b7f6b(local_c + ((uVar3 >> 1) * local_38 + local_3c) * 2,uVar3 >> 1,local_44,
                           local_6c,0,1);
    local_28[local_8] = local_c;
    (**(code **)*piVar2)(1);
    if (local_c == 0) goto LAB_004b257f;
    FUN_0046f824(local_ac,0,0x40);
    local_b8[0] = &PTR_FUN_0066651c;
    FUN_0046f847(s_Thumbnail_006c73cc,0xffffffff);
    (**(code **)(*param_2 + 0x74))(local_c,0x424d505f,local_8 + param_3,local_b8,0);
    FUN_00401f6f();
    local_8 = local_8 + 1;
    if (1 < local_8) {
      if (local_10 != (undefined4 *)0x0) {
        (**(code **)*local_10)(1);
      }
      local_10 = (undefined4 *)0x0;
      local_c = FUN_0041ffd9(0x14);
      if (local_c != 0) {
        piVar4 = (int *)FUN_00420048(local_c);
        piVar2 = local_68;
        for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar4 = *piVar2;
          piVar2 = piVar2 + 1;
          piVar4 = piVar4 + 1;
        }
        FUN_0042004f(local_c);
        FUN_0046f824(local_ac,0,0x40);
        local_b8[0] = &PTR_FUN_0066651c;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        (**(code **)(*param_2 + 0x74))(local_c,0x54484d42,param_3,local_b8,0);
        iVar6 = FUN_00401f6f();
        if (iVar6 != 0) {
          return;
        }
      }
      (**(code **)(*param_2 + 0x1c))();
      FUN_00401f6f();
      FUN_00465a06(local_28[0]);
      FUN_00401f6f();
      if (local_28[1] != 0) {
        FUN_00465a06(local_28[1]);
        FUN_00401f6f();
      }
      return;
    }
  } while( true );
}

