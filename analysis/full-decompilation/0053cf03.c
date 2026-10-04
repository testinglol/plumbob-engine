
uint FUN_0053cf03(undefined4 param_1,byte *param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uStack_8;
  
  bVar4 = DAT_006e4823;
  bVar3 = DAT_006e4822;
  bVar2 = DAT_006e481d;
  uStack_8 = 0;
  if (((byte)param_1 == 0) || (param_1._0_1_ = (byte)param_1 & ~*param_2, (byte)param_1 == 0)) {
    return 0;
  }
  bVar1 = *param_3 | (byte)param_1;
  if (bVar1 < 10) {
    if (bVar1 == 9) {
      param_4[1] = DAT_006e4823;
      *param_4 = bVar3;
      param_4[2] = 0;
      param_4[4] = 3;
      param_4[5] = 0;
      param_4[6] = 0;
      param_4[7] = 0;
      param_4[8] = 3;
      param_4[9] = 0;
      param_4[10] = 0;
      param_4[0xb] = 0;
    }
    else {
      if (bVar1 != 1) {
        if (bVar1 != 2) {
          if (bVar1 == 4) {
            *param_4 = DAT_006e481c;
          }
          else {
            if (bVar1 != 6) {
              if (bVar1 != 8) goto LAB_0053d154;
              *param_4 = DAT_006e4822;
              param_4[1] = bVar4;
              param_4[2] = 0;
              param_4[4] = 3;
              param_4[5] = 0;
              param_4[6] = 0;
              param_4[7] = 0;
              param_4[8] = 3;
              param_4[9] = 0;
              param_4[10] = 0;
              param_4[0xb] = 0;
              goto LAB_0053d11b;
            }
            *param_4 = DAT_006e481c;
          }
          param_4[2] = 0;
          param_4[1] = bVar2;
          param_4[4] = 3;
          param_4[5] = 0;
          param_4[6] = 0;
          param_4[7] = 0;
          goto LAB_0053d14b;
        }
        *param_4 = DAT_006e481c;
        param_4[1] = bVar2;
        param_4[2] = 0;
        param_4[4] = 3;
        param_4[5] = 0;
        param_4[6] = 0;
        param_4[7] = 0;
        param_4[8] = 1;
        param_4[9] = 0;
        param_4[10] = 0;
        param_4[0xb] = 0;
        goto LAB_0053d14e;
      }
      FUN_00461b74(&DAT_006e4822);
      *param_4 = (byte)param_1;
      param_4[1] = param_1._1_1_;
      param_4[2] = 0;
      param_4[4] = 3;
      param_4[5] = 0;
      param_4[6] = 0;
      param_4[7] = 0;
      param_4[8] = 0;
      param_4[9] = 0;
      param_4[10] = 0;
      param_4[0xb] = 0;
    }
    uStack_8 = 0x1000000;
    param_4[0x10] = 0;
    param_4[0xc] = 2;
    param_4[0xd] = 0;
    param_4[0xe] = 0;
    param_4[0xf] = 0;
  }
  else {
    if (bVar1 != 0x14) {
      if (bVar1 != 0x18) {
        if (bVar1 == 0x30) {
          *param_4 = DAT_006e481c;
          param_4[1] = bVar2;
          param_4[2] = 0;
          param_4[4] = 2;
          param_4[5] = 0;
          param_4[6] = 0;
          param_4[7] = 0;
          param_4[8] = 1;
          param_4[9] = 0;
          param_4[10] = 0;
          param_4[0xb] = 0;
          param_4[0x10] = 1;
        }
        else {
          if (bVar1 != 0x90) goto LAB_0053d154;
          *param_4 = DAT_006e4822;
          param_4[1] = bVar4;
          param_4[2] = 0;
          param_4[4] = 2;
          param_4[5] = 0;
          param_4[6] = 0;
          param_4[7] = 0;
          param_4[8] = 3;
          param_4[9] = 0;
          param_4[10] = 0;
          param_4[0xb] = 0;
          param_4[0x10] = 0;
        }
        uStack_8 = 0x1000000;
        param_4[0xc] = 0x10;
        param_4[0xd] = 0;
        param_4[0xe] = 0;
        param_4[0xf] = 0;
        goto LAB_0053d154;
      }
      *param_4 = DAT_006e4822;
      param_4[1] = bVar4;
      param_4[2] = 0;
      param_4[4] = 2;
      param_4[5] = 0;
      param_4[6] = 0;
      param_4[7] = 0;
      param_4[8] = 3;
      param_4[9] = 0;
      param_4[10] = 0;
      param_4[0xb] = 0;
LAB_0053d11b:
      uStack_8 = 0x1000000;
      param_4[0x10] = 0;
      param_4[0xc] = 2;
      param_4[0xd] = 0;
      param_4[0xe] = 0;
      param_4[0xf] = 0;
      goto LAB_0053d154;
    }
    *param_4 = DAT_006e481c;
    param_4[1] = bVar2;
    param_4[2] = 0;
    param_4[4] = 2;
    param_4[5] = 0;
    param_4[6] = 0;
    param_4[7] = 0;
LAB_0053d14b:
    param_4[8] = 2;
    param_4[9] = 0;
    param_4[10] = 0;
    param_4[0xb] = 0;
LAB_0053d14e:
    uStack_8 = 0x1000000;
    param_4[0x10] = 1;
    param_4[0xc] = 1;
    param_4[0xd] = 0;
    param_4[0xe] = 0;
    param_4[0xf] = 0;
  }
LAB_0053d154:
  return uStack_8 >> 0x18;
}

