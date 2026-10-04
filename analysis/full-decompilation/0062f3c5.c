
void __thiscall FUN_0062f3c5(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float *pfVar4;
  float *pfVar5;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = param_2;
  param_2 = 0;
  iVar1 = param_1 + iVar2 * 0xa0 + 0x34e4 + param_3 * 0x48;
  pfVar4 = (float *)(iVar2 * 0x900 + 0x380c + param_1);
  pfVar5 = (float *)(param_4 + 8);
  do {
    if (((*(int *)(iVar1 + 0x10) == 0) || (*(int *)(iVar1 + 0x18) == 0)) || (0x23 < param_2)) {
      uVar3 = *(undefined4 *)(iVar1 + 0x14);
    }
    else {
      uVar3 = 0;
    }
    FUN_0062c40f(pfVar5 + -2,&local_94,uVar3);
    pfVar5[-2] = local_94 + pfVar4[-2];
    pfVar4[-2] = local_4c;
    pfVar5[-1] = local_90 + pfVar4[-1];
    pfVar4[-1] = local_48;
    *pfVar5 = local_8c + *pfVar4;
    *pfVar4 = local_44;
    pfVar5[1] = local_88 + pfVar4[1];
    pfVar4[1] = local_40;
    pfVar5[2] = local_84 + pfVar4[2];
    pfVar4[2] = local_3c;
    pfVar5[3] = local_80 + pfVar4[3];
    pfVar4[3] = local_38;
    pfVar5[4] = local_7c + pfVar4[4];
    pfVar4[4] = local_34;
    pfVar5[5] = local_78 + pfVar4[5];
    pfVar4[5] = local_30;
    pfVar5[6] = local_74 + pfVar4[6];
    pfVar4[6] = local_2c;
    pfVar5[7] = local_70 + pfVar4[7];
    pfVar4[7] = local_28;
    pfVar5[8] = local_6c + pfVar4[8];
    pfVar4[8] = local_24;
    pfVar5[9] = local_68 + pfVar4[9];
    pfVar4[9] = local_20;
    pfVar5[10] = local_64 + pfVar4[10];
    pfVar4[10] = local_1c;
    pfVar5[0xb] = local_60 + pfVar4[0xb];
    pfVar4[0xb] = local_18;
    pfVar5[0xc] = local_5c + pfVar4[0xc];
    pfVar4[0xc] = local_14;
    param_2 = param_2 + 0x12;
    pfVar5[0xd] = local_58 + pfVar4[0xd];
    pfVar4[0xd] = local_10;
    pfVar5[0xe] = local_54 + pfVar4[0xe];
    pfVar4[0xe] = local_c;
    pfVar5[0xf] = local_50 + pfVar4[0xf];
    pfVar4[0xf] = local_8;
    pfVar4 = pfVar4 + 0x12;
    pfVar5 = pfVar5 + 0x12;
  } while (param_2 < 0x240);
  return;
}

