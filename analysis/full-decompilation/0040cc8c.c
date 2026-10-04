
void __thiscall FUN_0040cc8c(int param_1,int param_2,char param_3)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  
  puVar1 = &DAT_006c103c;
  if (param_2 != 0) {
    puVar1 = &DAT_006c1038;
  }
  FUN_005876ac(0xe,puVar1);
  iVar2 = FUN_0040cf46();
  if (iVar2 == 0) {
    if (param_2 == 1) {
      pcVar3 = s_child_006c1030;
    }
    else {
      pcVar3 = s_adult_006c1028;
    }
    FUN_005876ac(1,pcVar3);
  }
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  if (param_3 != '\0') {
    FUN_0040a5ea();
  }
  return;
}

