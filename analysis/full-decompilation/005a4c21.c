
void FUN_005a4c21(void)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  undefined4 uVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00405584(extraout_ECX + 0x114);
  cVar3 = FUN_005a4684();
  if (cVar3 == '\0') {
    FUN_005d5156(unaff_EBP + -0x30,s_No_Header_Token_found_in_Header_S_006d1fd4);
    FUN_00575805(unaff_EBP + -0x30);
    goto LAB_005a5014;
  }
  FUN_0046f847(*(int *)(extraout_ECX + 0x238) + *(int *)(extraout_ECX + 0x224),
               *(undefined4 *)(extraout_ECX + 0x23c));
  FUN_0041308b();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  iVar4 = FUN_004130d2(unaff_EBP + -0x1f8,0);
  if (iVar4 == 0) {
    iVar4 = FUN_00412fc7(unaff_EBP + -0x34);
    if (iVar4 != 0) goto LAB_005a4ce3;
    FUN_004131a0(0);
    pvVar5 = operator_new(*(uint *)(unaff_EBP + -0x34));
    iVar4 = FUN_00413178(pvVar5,unaff_EBP + -0x34);
    if (iVar4 == 0) {
      FUN_00431779(pvVar5,*(int *)(unaff_EBP + -0x34) + (int)pvVar5);
      FUN_006321f0(pvVar5);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004130c0();
      FUN_005d4956(&DAT_006c3d7c);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005d4956(&DAT_006c4a1c);
      *(undefined1 *)(unaff_EBP + -4) = 6;
LAB_005a4dbc:
      if (*(int *)(unaff_EBP + -0x20) != *(int *)(unaff_EBP + -0x24)) {
        piVar6 = (int *)FUN_005d4a0d(unaff_EBP + -0x40,s_const_Sint32_006d1f8c);
        iVar4 = piVar6[1];
        iVar1 = *piVar6;
        FUN_005b8770();
        if (iVar4 != iVar1) {
          uVar7 = FUN_005d4a0d(unaff_EBP + -0x88,&DAT_006c42ec);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005d499c(uVar7);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          do {
            FUN_005b8770();
            uVar7 = FUN_005d4be4(unaff_EBP + -0xa0,1);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            cVar3 = FUN_005d49dc(uVar7);
            if (cVar3 == '\0') {
              uVar7 = FUN_005d4be4(unaff_EBP + -0xd0,1);
              *(undefined1 *)(unaff_EBP + -4) = 9;
              cVar3 = FUN_005d49dc(uVar7);
              *(undefined1 *)(unaff_EBP + -4) = 8;
              FUN_005b8770();
              bVar2 = false;
              if (cVar3 != '\0') goto LAB_005a4e77;
            }
            else {
LAB_005a4e77:
              bVar2 = true;
            }
            *(undefined1 *)(unaff_EBP + -4) = 6;
            FUN_005b8770();
            if (!bVar2) goto LAB_005a4ebf;
            uVar7 = FUN_005d4c15(unaff_EBP + -0xdc,
                                 (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) + -1);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_005d499c(uVar7);
            *(undefined1 *)(unaff_EBP + -4) = 6;
          } while( true );
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
      goto LAB_005a5014;
    }
    FUN_005d5156(unaff_EBP + -0x30,s_Could_not_open_header___s__not_f_006d1f9c,
                 *(undefined4 *)(unaff_EBP + -500));
    FUN_00575805(unaff_EBP + -0x30);
    FUN_006321f0(pvVar5);
  }
  else {
LAB_005a4ce3:
    FUN_005d5156(unaff_EBP + -0x30,s_Could_not_open_header___s__not_f_006d1f9c,
                 *(undefined4 *)(unaff_EBP + -500));
    FUN_00575805(unaff_EBP + -0x30);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004130c0();
LAB_005a5014:
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
LAB_005a4ebf:
  uVar7 = FUN_005d4c15(unaff_EBP + -0xc4,1);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  cVar3 = FUN_005d49dc(uVar7);
  if (cVar3 == '\0') {
    uVar7 = FUN_005d4c15(unaff_EBP + -0xb8,1);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    cVar3 = FUN_005d49dc(uVar7);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005b8770();
    bVar2 = false;
    if (cVar3 != '\0') goto LAB_005a4f12;
  }
  else {
LAB_005a4f12:
    bVar2 = true;
  }
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  if (!bVar2) goto LAB_005a4f5f;
  uVar7 = FUN_005d4be4(unaff_EBP + -0x94,
                       (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) + -1);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_005d499c(uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  goto LAB_005a4ebf;
LAB_005a4f5f:
  uVar7 = FUN_005d4a0d(unaff_EBP + -0xac,&DAT_006c145c);
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_005d499c(uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  uVar7 = (*(code *)PTR_FUN_006d7014)(*(undefined4 *)(unaff_EBP + -0x4c));
  FUN_005a509f(unaff_EBP + -0x6c,unaff_EBP + -0x18);
  if (*(int *)(unaff_EBP + -0x6c) == 0) {
    FUN_005b86bd(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0x70) = uVar7;
    iVar4 = *(int *)(extraout_ECX + 0x250);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    FUN_005a534c(iVar4 + 1);
    FUN_005a52cd(unaff_EBP + -0xe8,unaff_EBP + -0x7c);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
  }
  goto LAB_005a4dbc;
}

