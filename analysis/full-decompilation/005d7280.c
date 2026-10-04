
undefined1 FUN_005d7280(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  HDC hdc;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    extraout_ECX[0x36] = 0x1b;
    piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))(unaff_EBP + -0x24);
    (**(code **)(*extraout_ECX + 0x60))(*puVar3,puVar3[1],puVar3[2],puVar3[3]);
    extraout_ECX[0x37] = 0;
    (**(code **)(*extraout_ECX + 0x90))(1,0);
    FUN_005d9884(extraout_ECX);
    FUN_005da5fb(extraout_ECX);
    pvVar4 = operator_new(0x50);
    *(void **)(unaff_EBP + -0x14) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      piVar2 = (int *)(**(code **)*DAT_006fe8bc)();
      uVar5 = (**(code **)(*piVar2 + 0x40))();
      iVar6 = FUN_005e6010(uVar5);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x3c] = iVar6;
    cVar1 = FUN_005d70ad(1);
    *(char *)(unaff_EBP + -0xd) = cVar1;
    if (cVar1 != '\0') {
      cVar1 = FUN_005d724d(1);
      *(char *)(unaff_EBP + -0xd) = cVar1;
      if (cVar1 != '\0') {
        hdc = GetDC(DAT_006fe8cc);
        SetMapMode(hdc,1);
        SetBkMode(hdc,1);
        if ((HPALETTE)extraout_ECX[0x35] != (HPALETTE)0x0) {
          SelectPalette(hdc,(HPALETTE)extraout_ECX[0x35],0);
        }
        RealizePalette(hdc);
        ReleaseDC(DAT_006fe8cc,hdc);
        uVar5 = (**(code **)(*DAT_006fe8bc + 0x1c))
                          (0,&cITSGraphicSystem::RTTI_Type_Descriptor,
                           &cTSGraphicSystemW95::RTTI_Type_Descriptor,0);
        iVar6 = FUN_006359f2(uVar5);
        extraout_ECX[0x3e] = iVar6;
      }
    }
  }
  FUN_005dbf32();
  if (*(char *)(unaff_EBP + -0xd) == '\0') {
    (**(code **)(*extraout_ECX + 0xcc))(1);
    (**(code **)(*extraout_ECX + 0x10))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

