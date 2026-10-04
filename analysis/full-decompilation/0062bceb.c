
undefined4 __thiscall FUN_0062bceb(int param_1,uint param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uStack_8;
  
  if ((param_2 & 0xfff00000) == 0xfff00000) {
    bVar4 = 4 - ((byte)(param_2 >> 0x11) & 3);
    *(byte *)(param_1 + 0x4a15) = (byte)(param_2 >> 9) & 1;
    *(byte *)(param_1 + 0x2490) = bVar4;
    bVar5 = (byte)(param_2 >> 6);
    uStack_8 = (CONCAT12(bVar5,(short)((param_2 >> 9 & 0xff) << 8)) & 0xff01ff) & 0xff03ffff;
    *(byte *)(param_1 + 0x4a16) = bVar5 & 3;
    *(byte *)(param_1 + 0x4a17) = (byte)(param_2 >> 4) & 3;
    *(byte *)(param_1 + 0x4a12) = (byte)(param_2 >> 0x10) & 1;
    *(byte *)(param_1 + 0x4a18) = (byte)(param_2 >> 3) & 1;
    bVar5 = (byte)(param_2 >> 0xc) & 0xf;
    *(byte *)(param_1 + 0x4a11) = (byte)(param_2 >> 0x13) & 1;
    *(byte *)(param_1 + 0x4a13) = bVar5;
    *(byte *)(param_1 + 0x4a19) = (byte)(param_2 >> 2) & 1;
    if ((param_2 & 0x100000) == 0) {
      *(undefined1 *)(param_1 + 0x4a0e) = 1;
      *(undefined1 *)(param_1 + 0x4a0d) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x4a0d) = 0;
      *(bool *)(param_1 + 0x4a0e) = (param_2 >> 0x13 & 1) == 0;
    }
    if (*(char *)(param_1 + 0x4a0d) == '\0') {
      uStack_8 = CONCAT13((char)(param_2 >> 10),(undefined3)uStack_8) & 0x3ffffff;
      *(char *)(param_1 + 0x4a14) = *(char *)(param_1 + 0x4a0e) * '\x03' + uStack_8._3_1_;
      *(byte *)(param_1 + 0x4a0f) =
           ((*(char *)(param_1 + 0x4a0e) != '\0') - 1U & 3) + uStack_8._3_1_;
    }
    else {
      *(byte *)(param_1 + 0x4a14) = ((byte)(param_2 >> 10) & 3) + 6;
    }
    iVar3 = (uStack_8._2_1_ != '\x03') + 1;
    *(int *)(param_1 + 0x4a40) = iVar3;
    uVar2 = *(undefined4 *)(&DAT_0067bb30 + (uint)*(byte *)(param_1 + 0x4a14) * 4);
    *(undefined4 *)(param_1 + 0x2488) = uVar2;
    *(undefined4 *)(param_1 + 0x2484) = uVar2;
    *(int *)(param_1 + 0x4a1c) = iVar3 * 0x20;
    if ((param_2 >> 0xc & 0xf) == 0) {
      FUN_00634c51(s_CMpegBase__ProcessHeader_returni_006da728);
    }
    else {
      sVar1 = *(short *)(&DAT_0067ba50 +
                        (((uint)*(byte *)(param_1 + 0x4a0e) * 3 + (uint)bVar4) * 0x10 + (uint)bVar5)
                        * 2);
      *(int *)(param_1 + 0x2494) = (int)sVar1;
      if (bVar4 != 1) {
        iVar3 = (sVar1 * 0x23280) / *(int *)(param_1 + 0x2484);
        *(int *)(param_1 + 0x2498) = iVar3;
        if ((bVar4 == 3) && (*(byte *)(param_1 + 0x4a0e) != 0)) {
          *(int *)(param_1 + 0x2498) = iVar3 >> 1;
        }
        if (uStack_8._1_1_ != '\0') {
          *(int *)(param_1 + 0x2498) = *(int *)(param_1 + 0x2498) + 1;
        }
        *(int *)(param_1 + 0x2498) = *(int *)(param_1 + 0x2498) + -4;
        return 0;
      }
    }
  }
  return 0xffffffff;
}

