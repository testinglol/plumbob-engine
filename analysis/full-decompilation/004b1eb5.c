
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b1eb5(int param_1,int *param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined **local_b4 [3];
  undefined1 local_a8 [64];
  int local_68;
  int local_64 [6];
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [2];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  local_38 = param_1;
  FUN_004aa1b9(&local_4c,&local_10,&local_44,&local_18);
  bVar5 = (char)DAT_006f0088 + 1;
  iVar6 = ((*(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x28)) - local_4c) + local_10 >>
          (bVar5 & 0x1f);
  iVar7 = ((*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c)) - local_44) + local_18 >>
          (bVar5 & 0x1f);
  local_8 = 1 << ((char)DAT_006f0088 - 1U & 0x1f);
  local_10 = local_10 / local_8;
  local_18 = local_18 / local_8;
  local_1c = (int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x18);
  *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = 0;
  FUN_004c482f();
  (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))(0);
  FUN_00466c7b();
  FUN_004e609e();
  local_40 = FUN_004e6141();
  uVar8 = 2;
  FUN_004e609e(2);
  FUN_004e6166(uVar8);
  local_24[0] = 0;
  local_24[1] = 0;
  local_c = (undefined4 *)0x0;
  local_8 = 0;
  do {
    piVar2 = (int *)FUN_004b2d29(iVar6,iVar7,0,1,local_10,local_18,_DAT_00666a48,local_64,2,
                                 CONCAT31((int3)((uint)&local_c >> 8),local_8 == 1),DAT_006f2a64,
                                 &local_c,0);
    *(undefined2 *)(*(int *)(DAT_006e486c + 0x1c) + 0x18) = (undefined2)local_1c;
    FUN_004c482f();
    (**(code **)(**(int **)(*(int *)(DAT_006e486c + 0x20) + 0x18) + 0x20))(local_1c);
    FUN_00466c7b();
    uVar8 = local_40;
    FUN_004e609e(local_40);
    FUN_004e6166(uVar8);
    if (piVar2 == (int *)0x0) {
LAB_004b21f4:
      if (local_c == (undefined4 *)0x0) {
        return;
      }
      (**(code **)*local_c)(1);
      return;
    }
    cVar1 = (**(code **)(*piVar2 + 0x20))(0x40);
    if (cVar1 == '\0') {
      if (piVar2 != (int *)0x0) {
        (**(code **)*piVar2)(1);
      }
      goto LAB_004b21f4;
    }
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    FUN_004c3766(piVar2,piVar2 + 5,CONCAT22((short)((uint)&local_34 >> 0x10),(short)piVar2[9]),
                 &local_34);
    local_68 = (iVar7 - local_28) - local_30;
    local_3c = (iVar6 - local_2c) - local_34;
    if (local_8 == 0) {
      local_64[1] = local_64[1] - local_30;
      local_64[0] = local_64[0] - local_34;
      local_64[4] = 0;
      local_64[3] = 0;
      local_64[5] = local_30;
      local_48 = local_34;
    }
    else {
      local_64[4] = local_30 - local_64[5];
      local_64[3] = local_34 - local_48;
    }
    local_14 = (**(code **)(*piVar2 + 0xcc))();
    uVar3 = (**(code **)(*piVar2 + 0xd0))();
    local_14 = FUN_004b7f6b(local_14 + ((uVar3 >> 1) * local_30 + local_34) * 2,uVar3 >> 1,local_3c,
                            local_68,0,1);
    local_24[local_8] = local_14;
    (**(code **)*piVar2)(1);
    if (local_14 == 0) goto LAB_004b21f4;
    FUN_0046f824(local_a8,0,0x40);
    local_b4[0] = &PTR_FUN_0066651c;
    FUN_0046f847(s_Thumbnail_006c73cc,0xffffffff);
    (**(code **)(*param_2 + 0x74))(local_14,0x424d505f,local_8 + param_3,local_b4,0);
    FUN_00401f6f();
    local_8 = local_8 + 1;
    if (1 < local_8) {
      if (local_c != (undefined4 *)0x0) {
        (**(code **)*local_c)(1);
      }
      local_c = (undefined4 *)0x0;
      iVar6 = FUN_0041ffd9(0x14);
      if (iVar6 != 0) {
        piVar4 = (int *)FUN_00420048(iVar6);
        piVar2 = local_64;
        for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar4 = *piVar2;
          piVar2 = piVar2 + 1;
          piVar4 = piVar4 + 1;
        }
        FUN_0042004f(iVar6);
        FUN_0046f824(local_a8,0,0x40);
        local_b4[0] = &PTR_FUN_0066651c;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        (**(code **)(*param_2 + 0x74))(iVar6,0x54484d42,param_3,local_b4,0);
        iVar6 = FUN_00401f6f();
        if (iVar6 != 0) {
          return;
        }
      }
      (**(code **)(*param_2 + 0x1c))();
      FUN_00401f6f();
      FUN_00465a06(local_24[0]);
      FUN_00401f6f();
      if (local_24[1] != 0) {
        FUN_00465a06(local_24[1]);
        FUN_00401f6f();
      }
      return;
    }
  } while( true );
}

