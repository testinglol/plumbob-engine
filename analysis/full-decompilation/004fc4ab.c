
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_004fc4ab(void)

{
  void *pvVar1;
  int iVar2;
  int extraout_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x7c) != 0) {
    FUN_004fc469();
  }
  switch(*(undefined4 *)(unaff_EBP + 8)) {
  case 0:
    uVar3 = 0x1530;
    uVar4 = 0x1531;
    break;
  case 1:
    uVar3 = 0x157c;
    uVar4 = 0x157d;
    break;
  case 2:
    uVar3 = 0x157e;
    uVar4 = 0x157f;
    break;
  case 3:
    uVar3 = 0x15e0;
    uVar4 = 0x15e1;
    break;
  case 4:
    uVar3 = 0x1614;
    uVar4 = 0x1615;
    break;
  case 5:
    uVar3 = 0x1612;
    uVar4 = 0x1613;
    break;
  case 6:
    uVar3 = 0x1616;
    uVar4 = 0x1617;
    break;
  case 7:
    uVar3 = 0x1618;
    uVar4 = 0x1619;
    break;
  default:
    uVar3 = *(undefined4 *)(unaff_EBP + 8);
    uVar4 = *(undefined4 *)(unaff_EBP + 8);
  }
  if (800 < *(int *)(*(int *)(extraout_ECX + 0x84) + 0x84) -
            *(int *)(*(int *)(extraout_ECX + 0x84) + 0x7c)) {
    uVar3 = uVar4;
  }
  FUN_005a5631(uVar3,(undefined4 *)(extraout_ECX + 0x78),4);
  pvVar1 = operator_new(0x108);
  *(void **)(unaff_EBP + 8) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00525af7(*(undefined4 *)(extraout_ECX + 0x78));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(extraout_ECX + 0x7c) = iVar2;
  if (iVar2 != 0) {
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0xf;
    }
    (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x20))(*(undefined4 *)(extraout_ECX + 0x7c));
    (**(code **)(**(int **)(extraout_ECX + 0x7c) + 0x138))();
    (**(code **)(**(int **)(extraout_ECX + 0x7c) + 0x94))();
  }
  (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
  (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
  (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
  (*(code *)**(undefined4 **)(*(int *)(DAT_006e486c + 0x4c) + 0x48))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

