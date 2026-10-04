
void __fastcall FUN_0047417a(undefined4 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (*(code *)**(undefined4 **)*param_1)(*(undefined2 *)(param_1 + 1));
  if (iVar2 != 0) {
    uVar1 = *(undefined2 *)(param_1 + 1);
    uVar3 = (*(code *)**(undefined4 **)*param_1)(uVar1);
    iVar2 = FUN_0047466b(param_1,uVar3,0x54505250,uVar1,0);
    *(undefined1 *)((int)param_1 + 7) = 0;
    *(undefined1 *)((int)param_1 + 6) = 0;
    if (iVar2 == -0x62) {
      FUN_004741c1();
    }
  }
  return;
}

