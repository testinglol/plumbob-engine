
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0047e457(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  int iVar4;
  short sVar5;
  
  FUN_00634c24();
  iVar4 = 0x100;
  FUN_0046f824(unaff_EBP + -0x1cc,0,0x100);
  *(undefined ***)(unaff_EBP + -0x1d8) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x2d8,0,0x100);
  iVar3 = DAT_006e486c;
  *(undefined ***)(unaff_EBP + -0x2e4) = &PTR_FUN_00666524;
  uVar2 = *(undefined4 *)(iVar3 + 0xc);
  sVar5 = (short)*(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  if (sVar5 != 7) {
    FUN_00465b21(unaff_EBP + -0x1d8,uVar2,0x84,*(int *)(unaff_EBP + 0xc) + 1);
    if (*(short *)(unaff_EBP + -0x1d0) == 0) {
      FUN_0046f847(s_owner_006c5190,0xffffffff);
      FUN_0046fa40((int)sVar5);
    }
    else {
      FUN_0046f917(unaff_EBP + -0x1d8,0xffffffff);
    }
    FUN_0046fa24(0x20);
  }
  switch(sVar5) {
  case 1:
    goto code_r0x0047e569;
  default:
    goto LAB_0047e756;
  case 3:
  case 4:
  case 5:
    iVar4 = 0x8d;
    break;
  case 6:
    iVar4 = 0x81;
    break;
  case 9:
  case 0x19:
    FUN_0047408c(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x18));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0047417a();
    FUN_0047422f(sVar5 != 9,(int)*(short *)(unaff_EBP + 0x10),unaff_EBP + -0x1d8);
    if (*(short *)(unaff_EBP + -0x1d0) != 0) {
      FUN_0046f917(unaff_EBP + -0x1d8,0xffffffff);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00474121();
      goto LAB_0047e7bf;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00474121();
    iVar4 = *(int *)(unaff_EBP + 8);
    break;
  case 0xc:
  case 0xe:
  case 0xf:
  case 0x1c:
  case 0x1d:
    iVar4 = 0x86;
    break;
  case 0x12:
  case 0x13:
  case 0x20:
    iVar4 = 200;
    break;
  case 0x15:
  case 0x26:
    iVar4 = 0xcc;
    break;
  case 0x17:
    iVar4 = 0xdb;
    break;
  case 0x18:
    iVar4 = 0xdd;
    break;
  case 0x1a:
    uVar1 = (short)*(ushort *)(unaff_EBP + 0x10) >> 0xd & 7;
    if (uVar1 == 0) {
      iVar4 = 0x1000;
    }
    else if (uVar1 == 1) {
      iVar4 = 0x2000;
    }
    else if (uVar1 != 2) goto LAB_0047e756;
    uVar1 = *(ushort *)(unaff_EBP + 0x10) & 0x7f;
    iVar4 = iVar4 + (*(int *)(unaff_EBP + 0x10) >> 7 & 0x3fU);
    iVar3 = (**(code **)**(undefined4 **)(unaff_EBP + 8))(iVar4);
    if (iVar3 != 0) {
      func_0x004736ca();
      *(undefined4 *)(unaff_EBP + -4) = 1;
      iVar4 = FUN_00473790(iVar3,iVar4);
      if (iVar4 == 0) {
        FUN_0046f824(unaff_EBP + -0x50,0,0x40);
        *(undefined ***)(unaff_EBP + -0x5c) = &PTR_FUN_0066651c;
        FUN_0046f8e4(unaff_EBP + -0xac);
        FUN_0046f847(&DAT_006c518c,0xffffffff);
        FUN_0046f917(unaff_EBP + -0x5c,0xffffffff);
        FUN_0046f847(&DAT_006c3d7c,0xffffffff);
        iVar4 = FUN_00473958(uVar1);
        if (iVar4 == 0) {
          FUN_0046fa40(uVar1);
        }
        else {
          FUN_0046f847(*(undefined4 *)(iVar4 + 0x18),0xffffffff);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00473729();
        goto LAB_0047e7bf;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00473729();
    }
LAB_0047e756:
    iVar4 = 0;
    break;
  case 0x21:
    iVar4 = 0xf3;
    break;
  case 0x22:
    iVar4 = 0xf9;
    break;
  case 0x23:
    iVar4 = 0xf5;
    break;
  case 0x24:
    iVar4 = 0x103;
  case 0:
code_r0x0047e55f:
code_r0x0047e575:
    uVar2 = FUN_00401f6f();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
    break;
  case 0x25:
    iVar4 = 0x103;
code_r0x0047e569:
    if (iRam006e55f4 == 0) goto code_r0x0047e55f;
    goto code_r0x0047e575;
  }
  FUN_0046f917(unaff_EBP + -0x2e4,0xffffffff);
  *(undefined2 *)(unaff_EBP + -0x1d0) = 0;
  **(undefined1 **)(unaff_EBP + -0x1d4) = 0;
  if ((short)iVar4 != 0) {
    FUN_00465b21(unaff_EBP + -0x1d8,*(undefined4 *)(unaff_EBP + -0x10),iVar4,
                 *(int *)(unaff_EBP + 0x10) + 1);
  }
  if (*(short *)(unaff_EBP + -0x1d0) == 0) {
    FUN_0046fa40((int)*(short *)(unaff_EBP + 0x10));
  }
  else {
    FUN_0046f917(unaff_EBP + -0x1d8,0xffffffff);
  }
LAB_0047e7bf:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

