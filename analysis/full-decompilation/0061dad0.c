
undefined4 * FUN_0061dad0(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  puVar6 = (undefined4 *)FUN_005a9320(0x1480);
  if (puVar6 != (undefined4 *)0x0) {
    puVar8 = puVar6;
    for (iVar7 = 0x520; uVar1 = s_Frank_Barchard_00677370._0_4_, iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    puVar6[3] = puVar6[3] | 3;
    puVar6[4] = 1;
    puVar6[5] = 1;
    puVar6[8] = uVar1;
    puVar6[9] = s_Frank_Barchard_00677370._4_4_;
    puVar6[10] = s_Frank_Barchard_00677370._8_4_;
    *(undefined2 *)(puVar6 + 0xb) = s_Frank_Barchard_00677370._12_2_;
    *(char *)((int)puVar6 + 0x2e) = s_Frank_Barchard_00677370[0xe];
    uVar4 = s_Saturation_00677d94._0_4_;
    puVar6[0x10] = DAT_006774d0;
    *(undefined1 *)(puVar6 + 0x11) = DAT_006774d4;
    puVar6[0x12] = DAT_00677d90;
    puVar6[0x16] = s_HSV_Adjust_00677d84._0_4_;
    puVar6[0x17] = s_HSV_Adjust_00677d84._4_4_;
    *(undefined2 *)(puVar6 + 0x18) = s_HSV_Adjust_00677d84._8_2_;
    *(char *)((int)puVar6 + 0x62) = s_HSV_Adjust_00677d84[10];
    uVar1 = DAT_00677d80;
    puVar6[0x78] = uVar4;
    puVar6[0x79] = s_Saturation_00677d94._4_4_;
    *(undefined2 *)(puVar6 + 0x7a) = s_Saturation_00677d94._8_2_;
    *(char *)((int)puVar6 + 0x1ea) = s_Saturation_00677d94[10];
    puVar6[0x28] = uVar1;
    uVar5 = DAT_006de560;
    puVar6[0x22] = 0;
    puVar6[0x24] = 0;
    puVar6[0x26] = 0;
    puVar6[0x72] = 0;
    puVar6[0x74] = 0;
    puVar6[0x76] = 0;
    puVar6[0xc2] = 0;
    puVar6[0xc4] = 0;
    puVar6[0xc6] = 0;
    *puVar6 = 0x46485356;
    puVar6[1] = 0x1480;
    puVar6[2] = 100;
    puVar6[7] = 0;
    puVar6[0x1e] = 4;
    puVar6[0x20] = 2;
    puVar6[0x23] = 0xc0668000;
    puVar6[0x25] = 0x40668000;
    puVar6[0x27] = 0;
    *(undefined1 *)(puVar6 + 0x30) = uVar5;
    puVar6[0x70] = 2;
    puVar6[0x73] = 0xc0590000;
    puVar6[0x75] = 0x40590000;
    puVar6[0x77] = 0;
    *(undefined1 *)(puVar6 + 0x80) = uVar5;
    puVar6[0xc0] = 2;
    puVar6[0xc3] = 0xc0590000;
    puVar6[0xc5] = 0x40590000;
    puVar6[199] = 0;
    puVar6[200] = s_Brightness_00677d74._0_4_;
    puVar6[0xc9] = s_Brightness_00677d74._4_4_;
    *(undefined2 *)(puVar6 + 0xca) = s_Brightness_00677d74._8_2_;
    puVar6[0x116] = 0;
    puVar6[0x112] = 0;
    puVar6[0x114] = 0;
    cVar3 = s_Brightness_00677d74[10];
    puVar6[0x117] = 0;
    uVar1 = s_Value_00677d6c._0_4_;
    *(char *)((int)puVar6 + 0x32a) = cVar3;
    puVar6[200] = uVar1;
    uVar2 = s_Value_00677d6c._4_2_;
    puVar6[0x110] = 2;
    puVar6[0x113] = 0xc0590000;
    puVar6[0x115] = 0x40590000;
    *(undefined2 *)(puVar6 + 0xc9) = uVar2;
    *(undefined1 *)(puVar6 + 0xd0) = uVar5;
  }
  return puVar6;
}

