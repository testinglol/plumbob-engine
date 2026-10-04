
undefined4 FUN_0044ae48(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  byte *pbVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_28c [4];
  undefined4 uStack_288;
  undefined *puStack_284;
  uint *puStack_280;
  char *pcStack_27c;
  
  FUN_00634c24();
  pbVar4 = *(byte **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x2c) = extraout_ECX;
  bVar1 = *pbVar4;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if ((uint)*(byte *)(*(int *)(unaff_EBP + 8) + 6) <= (uint)bVar1) {
    puStack_280 = (uint *)(unaff_EBP + 8);
    pcStack_27c = "";
    *(undefined4 *)(unaff_EBP + 8) = 8;
                    /* WARNING: Subroutine does not return */
    puStack_284 = &UNK_0044b408;
    __CxxThrowException_8();
  }
  pcStack_27c = (char *)0x44ae85;
  iVar6 = FUN_004752fc();
  bVar2 = pbVar4[2];
  *(int *)(unaff_EBP + -0x34) = (int)*(short *)(iVar6 + (uint)bVar1 * 2);
  if ((uint)*(byte *)(*(int *)(unaff_EBP + 8) + 6) <= (uint)bVar2) {
    puStack_280 = (uint *)(unaff_EBP + 8);
    pcStack_27c = "";
    *(undefined4 *)(unaff_EBP + 8) = 8;
                    /* WARNING: Subroutine does not return */
    puStack_284 = (undefined *)0x44b3f3;
    __CxxThrowException_8();
  }
  pcStack_27c = (char *)0x44aeac;
  iVar6 = FUN_004752fc();
  bVar1 = pbVar4[1];
  *(int *)(unaff_EBP + -0x18) = (int)*(short *)(iVar6 + (uint)bVar2 * 2);
  if ((uint)*(byte *)(*(int *)(unaff_EBP + 8) + 6) <= (uint)bVar1) {
    puStack_280 = (uint *)(unaff_EBP + 8);
    pcStack_27c = "";
    *(undefined4 *)(unaff_EBP + 8) = 8;
                    /* WARNING: Subroutine does not return */
    puStack_284 = (undefined *)0x44b3de;
    __CxxThrowException_8();
  }
  pcStack_27c = (char *)0x44aed3;
  iVar7 = FUN_004752fc();
  iVar6 = DAT_006e486c;
  sVar3 = *(short *)(iVar7 + (uint)bVar1 * 2);
  puStack_280 = (uint *)(uint)pbVar4[3];
  pcStack_27c = (char *)0xffffffff;
  *(uint **)(unaff_EBP + -0x28) = puStack_280;
  uVar8 = *(undefined4 *)(iVar6 + 0x24);
  puStack_284 = (undefined *)(unaff_EBP + -0x10);
  *(bool *)(unaff_EBP + 0xf) = sVar3 < 0;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar8;
  uStack_288 = 0x44aefc;
  iVar6 = FUN_0042612b();
  pcStack_27c = (char *)0x44af0b;
  (**(code **)(*(int *)**(undefined4 **)(*(int *)(unaff_EBP + -0x10) + 8) + 0x10))();
  pcStack_27c = (char *)0x44af18;
  (**(code **)(*(int *)**(undefined4 **)(*(int *)(unaff_EBP + -0x10) + 8) + 0x14))();
  if ((iVar6 != 0) || (*(int *)(unaff_EBP + -0x10) == 0)) goto LAB_0044b3b5;
  puVar5 = *(uint **)(*(int *)(unaff_EBP + -0x10) + 8);
  if (*(char *)(unaff_EBP + 0xf) != '\0') {
    pcStack_27c = (char *)0x44b287;
    FUN_00408b9d();
    *(undefined4 *)(unaff_EBP + -4) = 4;
    pcStack_27c = (char *)0x44b299;
    FUN_00408b9d();
    pcStack_27c = (char *)0x0;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    puStack_280 = *(uint **)(*(int *)(unaff_EBP + -0x2c) + 0x11c);
    puStack_284 = (undefined *)0x44b2b3;
    FUN_00409377();
    pcStack_27c = (char *)0x0;
    puStack_284 = (undefined *)0x44b2c0;
    puStack_280 = puVar5;
    FUN_00409377();
    pcStack_27c = (char *)0x0;
    puStack_280 = (uint *)0x44b2cc;
    puStack_280 = (uint *)FUN_0040cc3f();
    puStack_284 = (undefined *)0x44b2d8;
    FUN_0040cc8c();
    pcStack_27c = (char *)0x0;
    *(undefined1 **)(unaff_EBP + 0xc) = auStack_28c;
    FUN_0040d069(auStack_28c);
    FUN_0040d091();
    pcStack_27c = (char *)0x0;
    puStack_280 = (uint *)0x44b304;
    puStack_280 = (uint *)FUN_0040cd0e();
    puStack_284 = (undefined *)0x44b310;
    FUN_0040cea3();
    pcStack_27c = (char *)0x0;
    puStack_280 = (uint *)0x44b31c;
    puStack_280 = (uint *)FUN_0040d106();
    puStack_284 = (undefined *)0x44b328;
    FUN_0040d16d();
    pcStack_27c = (char *)0x0;
    puStack_280 = (uint *)0x44b334;
    puStack_280 = (uint *)FUN_0040d46a();
    puStack_284 = (undefined *)0x44b340;
    FUN_0040d4d1();
    pcStack_27c = (char *)0x1;
    puStack_280 = (uint *)0x44b34d;
    FUN_004094f4();
    pcStack_27c = (char *)0x0;
    puStack_280 = (uint *)0x44b359;
    FUN_004094f4();
    pcStack_27c = (char *)0x44b360;
    FUN_00457ea7();
    pcStack_27c = (char *)0x44b369;
    pcStack_27c = (char *)FUN_00457ea7();
    puStack_280 = (uint *)0x44b371;
    FUN_005d499c();
    puStack_280 = (uint *)*puVar5;
    pcStack_27c = (char *)CONCAT22((short)(puVar5[0x18] >> 0x10),
                                   *(undefined2 *)(puVar5[0x18] + 0x52));
    puStack_284 = (undefined *)0x44b383;
    FUN_004063b5();
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    *(undefined2 *)(*(int *)(unaff_EBP + 8) + 4) = **(undefined2 **)(unaff_EBP + -0x10);
    pcStack_27c = (char *)0x44b3a6;
    FUN_00408c4f();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pcStack_27c = (char *)0x44b3b5;
    FUN_00408c4f();
    goto LAB_0044b3b5;
  }
  pcStack_27c = (char *)0x44af3f;
  uVar8 = FUN_00401f77();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar8;
  pcStack_27c = (char *)0x44af4d;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x278) = &PTR_FUN_0066643c;
  pcStack_27c = (char *)0x0;
  puStack_280 = (uint *)0x2000;
  puStack_284 = *(undefined **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_288 = 0x44af6e;
  FUN_00470383();
  pcStack_27c = (char *)0xffffffff;
  puStack_280 = (uint *)(*(int *)(unaff_EBP + -0x34) + 1);
  puStack_284 = (undefined *)0x44af80;
  pcStack_27c = (char *)FUN_004705f2();
  puStack_280 = (uint *)0x44af89;
  FUN_0040bfed();
  if (*(short *)(unaff_EBP + -0x3c) == 0) {
    puStack_280 = (uint *)(unaff_EBP + 8);
    pcStack_27c = "";
    *(undefined4 *)(unaff_EBP + 8) = 0x3b;
                    /* WARNING: Subroutine does not return */
    puStack_284 = (undefined *)0x44afa4;
    __CxxThrowException_8();
  }
  *(uint *)(unaff_EBP + 0xc) = (uint)(sVar3 < 0x12);
  iVar6 = *(int *)(unaff_EBP + -0x28);
  if (iVar6 == 0) {
    uVar9 = (uint)(*(int *)(unaff_EBP + -0x18) != 0);
  }
  else {
    if (iVar6 == 1) {
      uVar9 = (*(int *)(unaff_EBP + -0x18) != 0) + 2;
    }
    else {
      if (iVar6 != 2) {
        uVar9 = *(uint *)(unaff_EBP + 8);
        goto LAB_0044afe9;
      }
      uVar9 = (*(int *)(unaff_EBP + -0x18) != 0) + 4;
    }
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
  }
LAB_0044afe9:
  pcStack_27c = (char *)0x44aff4;
  FUN_00408b9d();
  pcStack_27c = (char *)0x0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puStack_284 = (undefined *)0x44b005;
  puStack_280 = puVar5;
  FUN_00409377();
  pcStack_27c = (char *)0x0;
  puStack_280 = *(uint **)(unaff_EBP + 0xc);
  puStack_284 = (undefined *)0x44b014;
  FUN_0040cc8c();
  pcStack_27c = (char *)0x0;
  *(undefined1 **)(unaff_EBP + 0xc) = auStack_28c;
  FUN_0042c904(unaff_EBP + -0x44);
  FUN_0040d091();
  pcStack_27c = (char *)0x0;
  puStack_284 = (undefined *)0x44b03e;
  puStack_280 = (uint *)uVar9;
  FUN_0040cea3();
  pcStack_27c = (char *)0x44b049;
  uVar8 = FUN_0040d0d9();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar8;
  iVar6 = *(int *)(unaff_EBP + -0x28);
  uVar9 = 0;
  if (iVar6 == 0) {
    pcStack_27c = (char *)0x44b06a;
    uVar9 = FUN_0040d43d();
  }
  else if ((iVar6 == 1) || (iVar6 == 2)) {
    uVar9 = 0;
  }
  pcStack_27c = (char *)0x44b077;
  iVar6 = FUN_0040cd0e();
  if (-1 < iVar6) {
    if (iVar6 < 2) {
      if ((*(int *)(unaff_EBP + 0xc) != 0) && (uVar9 != 0)) {
        pcStack_27c = (char *)0x0;
        puStack_280 = (uint *)0x44b196;
        uVar10 = FUN_0046f556();
        puStack_280 = (uint *)(uVar10 % uVar9);
        puStack_284 = (undefined *)0x44b1a6;
        FUN_0040d4d1();
        pcStack_27c = (char *)0x0;
        puStack_280 = (uint *)0x44b1ac;
        uVar9 = FUN_0046f556();
        puStack_280 = (uint *)(uVar9 % *(uint *)(unaff_EBP + 0xc));
        puStack_284 = (undefined *)0x44b1bd;
        FUN_0040d16d();
        pcStack_27c = (char *)0x1;
        puStack_280 = (uint *)0x44b1ca;
        FUN_004094f4();
        pcStack_27c = &DAT_006e4a70;
        puStack_280 = (uint *)0x44b1d7;
        FUN_005b86bd();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        if (*(int *)(unaff_EBP + -0x20) == *(int *)(unaff_EBP + -0x24)) {
          pcStack_27c = (char *)0x5;
          puStack_280 = (uint *)0x44b1ea;
          pcStack_27c = (char *)FUN_00435ff3();
          if (pcStack_27c == (char *)0x0) {
            pcStack_27c = s_No_childname_006c4034;
          }
          puStack_280 = (uint *)0x44b1fd;
          FUN_005d4bbf();
        }
        pcStack_27c = (char *)0x44b204;
        FUN_00457ea7();
        pcStack_27c = (char *)(unaff_EBP + -0x24);
        puStack_280 = (uint *)0x44b211;
        FUN_005d499c();
        puStack_280 = (uint *)*puVar5;
        pcStack_27c = (char *)CONCAT22((short)(puVar5[0x18] >> 0x10),
                                       *(undefined2 *)(puVar5[0x18] + 0x52));
        puStack_284 = (undefined *)0x44b223;
        FUN_004063b5();
        *(undefined4 *)(unaff_EBP + -0x14) = 1;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(undefined2 *)(*(int *)(unaff_EBP + 8) + 4) = **(undefined2 **)(unaff_EBP + -0x10);
        goto LAB_0044b175;
      }
LAB_0044b243:
      pcStack_27c = (char *)0x0;
      puStack_280 = (uint *)0x44b24f;
      FUN_004094f4();
      pcStack_27c = *(char **)(unaff_EBP + -0x10);
      puStack_280 = (uint *)0x44b25a;
      FUN_00427017();
    }
    else if (iVar6 < 6) {
      if (*(int *)(unaff_EBP + 0xc) == 0) goto LAB_0044b243;
      iVar6 = *(int *)(unaff_EBP + -0x2c);
      pcStack_27c = (char *)0x0;
      sVar3 = *(short *)(*(int *)(iVar6 + 0xdc) + 0x100);
      if (sVar3 == -1) {
        puStack_280 = (uint *)0x44b0b6;
        uVar9 = FUN_0046f556();
        puStack_280 = (uint *)(uVar9 % *(uint *)(unaff_EBP + 0xc));
      }
      else {
        puStack_280 = (uint *)(int)sVar3;
      }
      puStack_284 = (undefined *)0x44b0cd;
      FUN_0040d16d();
      pcStack_27c = (char *)0x1;
      *(undefined2 *)(*(int *)(iVar6 + 0xdc) + 0x100) = 0xffff;
      puStack_280 = (uint *)0x44b0e8;
      FUN_004094f4();
      pcStack_27c = &DAT_006e4a70;
      puStack_280 = (uint *)0x44b0f5;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (*(int *)(unaff_EBP + -0x20) == *(int *)(unaff_EBP + -0x24)) {
        pcStack_27c = (char *)0x5;
        puStack_280 = (uint *)0x44b108;
        pcStack_27c = (char *)FUN_00435ff3();
        if (pcStack_27c == (char *)0x0) {
          pcStack_27c = s_No_childname_006c4034;
        }
        puStack_280 = (uint *)0x44b11b;
        FUN_005d4bbf();
      }
      pcStack_27c = (char *)0x44b122;
      FUN_00457ea7();
      pcStack_27c = (char *)(unaff_EBP + -0x24);
      puStack_280 = (uint *)0x44b12f;
      FUN_005d499c();
      puStack_280 = (uint *)*puVar5;
      pcStack_27c = (char *)CONCAT22((short)(puVar5[0x18] >> 0x10),
                                     *(undefined2 *)(puVar5[0x18] + 0x52));
      puStack_284 = (undefined *)0x44b141;
      FUN_004063b5();
      *(undefined2 *)(*(int *)(unaff_EBP + 8) + 4) = **(undefined2 **)(unaff_EBP + -0x10);
      pcStack_27c = (char *)0x1;
      puStack_280 = (uint *)0x1f;
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      puStack_284 = (undefined *)0x44b15e;
      puStack_284 = (undefined *)FUN_0045741b();
      uStack_288 = 0x44b164;
      puStack_284 = (undefined *)FUN_004e988f();
      uStack_288 = 0x44b16b;
      FUN_004e8d99();
      *(undefined1 *)(unaff_EBP + -4) = 1;
LAB_0044b175:
      pcStack_27c = (char *)0x44b17a;
      FUN_005b8770();
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  pcStack_27c = (char *)0x44b268;
  FUN_00408c4f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pcStack_27c = (char *)0x44b277;
  FUN_00470467();
LAB_0044b3b5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

