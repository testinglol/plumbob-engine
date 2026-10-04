
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00413b0e(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  extraout_ECX[9] = 0;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0x11] = 0x49;
  uVar1 = FUN_006359f2(DAT_006fe8bc,0,&cTSFrameWork::RTTI_Type_Descriptor,
                       &cTSFrameWork::RTTI_Type_Descriptor,0);
  extraout_ECX[0x12] = uVar1;
  uVar1 = (**(code **)(*DAT_006fe8bc + 0x1c))
                    (0,&cITSGraphicSystem::RTTI_Type_Descriptor,
                     &cTSGraphicSystemW95::RTTI_Type_Descriptor,0);
  uVar1 = FUN_006359f2(uVar1);
  extraout_ECX[0x13] = uVar1;
  uVar1 = (**(code **)(*DAT_006fe8bc + 0x18))
                    (0,&cTSWinMgrW95::RTTI_Type_Descriptor,&cTSWinMgrW95::RTTI_Type_Descriptor,0);
  uVar1 = FUN_006359f2(uVar1);
  extraout_ECX[0x14] = uVar1;
  uVar1 = (**(code **)(*DAT_006fe8bc + 0x10))
                    (0,&cITSFontSys::RTTI_Type_Descriptor,&cTSFontSys::RTTI_Type_Descriptor,0);
  uVar1 = FUN_006359f2(uVar1);
  extraout_ECX[0x15] = uVar1;
  pvVar2 = operator_new(0x10);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_005bc0be();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar4 = thunk_FUN_005bdf5b();
  *(byte *)(extraout_ECX + 0x16) = (byte)(uVar4 >> 0x17) & 1;
  *(byte *)((int)extraout_ECX + 0x5d) = (byte)(uVar4 >> 4) & 1;
  if ((uVar4 >> 4 & 1) != 0) {
    DAT_006e5470 = 1;
    DAT_006fe8b0 = 1;
  }
  uVar1 = FUN_005bc285();
  extraout_ECX[0x18] = uVar1;
  *(undefined1 *)(extraout_ECX + 0x19) = 1;
  *(undefined2 *)((int)extraout_ECX + 0x66) = 0;
  FUN_005bc302(unaff_EBP + -0x10,unaff_EBP + -0x18);
  uVar5 = FUN_005bc2d8();
  uVar4 = *(uint *)(unaff_EBP + -0x10);
  if ((uVar4 < 0x81) || (uVar5 < 600)) {
    *(undefined2 *)((int)extraout_ECX + 0x6a) = 0;
  }
  else if ((uVar4 < 0xc1) || (uVar5 < 1000)) {
    *(undefined2 *)((int)extraout_ECX + 0x6a) = 1;
  }
  else {
    *(undefined2 *)((int)extraout_ECX + 0x6a) = 2;
  }
  if (uVar4 < 0x80) {
    if (0xff < uVar4) {
      _DAT_006d1a48 = 200000;
      DAT_006d1a4c = 640000;
      _DAT_006d1a50 = 800000;
      DAT_006d1a54 = 0x271000;
    }
  }
  else {
    _DAT_006d1a48 = 20000;
    DAT_006d1a4c = 160000;
    _DAT_006d1a50 = 200000;
    DAT_006d1a54 = 640000;
  }
  *(undefined1 *)((int)extraout_ECX + 0x59) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x5a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x5b) = 0;
  *(undefined1 *)(extraout_ECX + 0x17) = 0;
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

