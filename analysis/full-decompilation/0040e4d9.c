
void FUN_0040e4d9(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int local_1cc;
  undefined4 local_134;
  undefined1 local_12c [256];
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined **local_1c;
  undefined4 local_18;
  undefined1 local_10 [8];
  int local_8;
  
  iVar2 = (**(code **)*param_1)();
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0046fab1(&DAT_006c10a0,iVar4);
      if (iVar3 == -1) {
        iVar3 = (**(code **)*param_1)();
      }
      if (iVar4 < iVar3) {
        FUN_0046f824(local_12c,0,0x100);
        FUN_0046f847(param_1[1] + iVar4,iVar3 - iVar4);
        FUN_0047274f(local_134);
        iVar4 = iVar3 + -1;
      }
      else {
        iVar3 = iVar4 + 1;
        if (iVar3 < iVar2) {
          cVar1 = *(char *)(param_1[1] + iVar3);
          iVar4 = iVar3;
          if ((cVar1 == 'b') || (cVar1 == 'B')) {
            FUN_00472fca(*(undefined4 *)(local_8 + 8),2);
            FUN_0046f824(local_10,0,8);
            local_1c = &PTR_FUN_00666644;
            FUN_0046f847(local_1cc + 6,3);
            uVar6 = local_18;
LAB_0040e617:
            FUN_0047274f(uVar6);
          }
          else if ((cVar1 == 'g') || (cVar1 == 'G')) {
            iVar3 = FUN_0040cd0e();
            if (iVar3 == 1) {
              puVar5 = &DAT_006c0f9c;
            }
            else {
              puVar5 = &DAT_006c0f98;
            }
            FUN_004727bd(puVar5,&DAT_006c0fa0);
          }
          else if ((cVar1 == 'c') || (cVar1 == 'C')) {
            FUN_0040d069(local_2c);
            uVar6 = local_28;
            goto LAB_0040e617;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return;
}

